#include <stdio.h>        /* fprintf */
#include <string.h>
#include <stdlib.h>       /* contains exit */
#include <unistd.h>       /* contains read/write */
#include <fcntl.h>
#include <sys/stat.h>

#if !defined(DOS) && !defined(Win32)
#define O_BINARY 0
#endif

#define SECTOR         512

void die (const char* str)
 {
   fprintf(stderr,"%s\n",str);
   exit(1);
 }

int main (int argc, char** argv)
 { 
   int fd, fd_out;
   char bootsector[SECTOR];
   char setupsector[SECTOR];
   struct stat info;
   unsigned short setup_size;
   int bytes_read, to_read;
   unsigned int dc, st, sh, ss, tt, th, ts; 
   unsigned char bios_device_code, start_track, start_head, start_sector;
   unsigned short total_tracks, total_heads, total_sectors;

   if (argc != 6)
      die ("usage: build bootsector setup-code system-image dev.info bootdisk-image\n\n"
	   "dev.info: BIOS-dev.code:total-tracks:-heads:-sectors:start-track:-head:-sector\n"
	   "BIOS-devicecode: 0=fd0, 1=fd1, ..., 128=hd0, 129=hd1, ...\n"
	   "Example: to boot from a 3.5\" floppy disk use \"0:80:2:18:0:0:1\"\n");

   sscanf (argv[4], "%u:%u:%u:%u:%u:%u:%u", &dc, &tt, &th, &ts, &st, &sh, &ss);
   bios_device_code = (unsigned char)dc;
   total_tracks     = (unsigned short)tt;
   total_sectors    = (unsigned short)ts;
   total_heads      = (unsigned short)th;
   start_track      = (unsigned char)st;
   start_head       = (unsigned char)sh;
   start_sector     = (unsigned char)ss;

   printf ("BIOS-devicecode: 0x%x\n", bios_device_code);
   printf ("Total T/H/S:     (%d/%d/%d)\n", total_tracks, total_heads, 
	   total_sectors);
   printf ("Start T/H/S:     (%d/%d/%d)\n\n", start_track, start_head, 
	   start_sector);

   if ((fd_out = open (argv[5], O_WRONLY|O_CREAT|O_TRUNC|O_BINARY, 0644)) < 0)
      die ("Unable to open output file.");

   if ((fd = open (argv[1], O_RDONLY|O_BINARY, 0)) < 0)
      die ("Unable to open input file.");

   if (read (fd, bootsector, SECTOR) < 0)
      die ("Unable to read bootsector.");

   close (fd);

   if (stat (argv[2], &info) != 0)
      die ("Can't stat setup file.");

   setup_size = (unsigned short)
    ((info.st_size + SECTOR - 1) / SECTOR);
   printf ("Setup size is %d sectors.\n", (int)setup_size);

   if (stat (argv[3], &info) != 0)
      die ("Can't stat system file.");
   to_read = info.st_size;
   printf ("System size is %d bytes.\n", to_read);

#if 0
   *(unsigned short*)(bootsector+4) = total_tracks;
   *(unsigned short*)(bootsector+6) = total_heads;
   *(unsigned short*)(bootsector+8) = total_sectors;

   *(unsigned short*)(bootsector+10) = setup_size;
   *(unsigned short*)(bootsector+12) =
    (unsigned short)((to_read + SECTOR - 1) / SECTOR);
   *(unsigned char*)(bootsector+14) = bios_device_code;
   *(unsigned char*)(bootsector+15) = start_track;
   *(unsigned char*)(bootsector+16) = start_head;
   *(unsigned char*)(bootsector+17) = start_sector;
#else
   *(unsigned char*)(bootsector+4) = (total_tracks) & 0xff;
   *(unsigned char*)(bootsector+5) = (total_tracks >> 8) & 0xff;
   *(unsigned char*)(bootsector+6) = (total_heads) & 0xff;
   *(unsigned char*)(bootsector+7) = (total_heads >> 8) & 0xff;         
   *(unsigned char*)(bootsector+8) = (total_sectors) & 0xff;
   *(unsigned char*)(bootsector+9) = (total_sectors >> 8) & 0xff;         

   *(unsigned char*)(bootsector+10) = (setup_size) & 0xff;
   *(unsigned char*)(bootsector+11) = (setup_size >> 8) & 0xff;         
   *(unsigned char*)(bootsector+12) =
    ((unsigned short)((to_read + SECTOR - 1) / SECTOR)) & 0xff;
   *(unsigned char*)(bootsector+13) =
    ((unsigned short)((to_read + SECTOR - 1) / SECTOR) >> 8) & 0xff;
   *(unsigned char*)(bootsector+14) = bios_device_code;
   *(unsigned char*)(bootsector+15) = start_track;
   *(unsigned char*)(bootsector+16) = start_head;
   *(unsigned char*)(bootsector+17) = start_sector;
#endif         

   write (fd_out, bootsector, SECTOR);

   if ((fd = open (argv[2], O_RDONLY|O_BINARY, 0)) < 0)
      die ("Unable to open setup file.");

   do
    {
      if ((bytes_read = read (fd, setupsector, SECTOR)) < 0)
	 die ("Unable to read setup.");

      if (bytes_read > 0)
	 write (fd_out, setupsector, SECTOR);

    } while (bytes_read > 0);
      

   close (fd);

   if ((fd = open (argv[3], O_RDONLY|O_BINARY, 0)) < 0)
      die ("Unable to open system file.");
   
   while (to_read > 0)
    {
      int l;

      l = (to_read < SECTOR)?to_read:SECTOR;
	
      if ((bytes_read = read (fd, setupsector, l)) != l)
	 die ("Unable to read system.");

      write (fd_out, setupsector, l);

      to_read -= l;
    }
      
   close (fd);
   close (fd_out);
         
   return 0;         
 }




