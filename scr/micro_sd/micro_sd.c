#include "string.h"

#include "diskio.h"
#include "ff.h"

#include "app_assert.h"
#include "app_log.h"

#include "sl_sleeptimer.h"

static const char  str[] = "Silabs SD Card I/O Example via SPI!\r\n";
static const char *fst[] = {"", "FAT12", "FAT16", "FAT32", "exFAT"};

BYTE f_work[FF_MAX_SS]; // Work area (larger is better for processing time)

void micro_sd_init(void)
{
  FATFS   fs;
  FATFS  *pfs;
  FIL     fil;
  DWORD   fre_clust;
  FRESULT ret_code;
  UINT    bw;
  UINT    br;

  // Give a work area to the default drive
  ret_code = f_mount(&fs, "", 0);
  app_assert_status(ret_code);

  // Show logical drive status
  ret_code = f_getfree("", &fre_clust, &pfs);
  app_assert_status(ret_code);
  app_log("-------------- Volume status --------------\n\r");
  app_log(("FAT type = %s\nBytes/Cluster = %lu\nNumber of FATs = %u\n"
           "Root DIR entries = %u\nSectors/FAT = %lu\n"
           "Number of clusters = %lu\nVolume start (lba) = %lu\n"
           "FAT start (lba) = %lu\nDIR start (lba,clustor) = %lu\n"
           "Data start (lba) = %lu\n%lu KiB total disk space.\n"
           "%lu KiB available.\n\n"),
          fst[pfs->fs_type], (DWORD)pfs->csize * 512, pfs->n_fats, pfs->n_rootdir, pfs->fsize, pfs->n_fatent - 2,
          (DWORD)pfs->volbase, (DWORD)pfs->fatbase, (DWORD)pfs->dirbase, (DWORD)pfs->database,
          (pfs->n_fatent - 2) * (pfs->csize / 2), fre_clust * (pfs->csize / 2));

  // app_log("-------- Open file to write and read again ---------\n\r");
  // // Open file to write
  // ret_code = f_open(&fil, "hello.txt", FA_OPEN_ALWAYS | FA_READ | FA_WRITE);
  // app_assert_status(ret_code);

  // // Write a message
  // ret_code = f_write(&fil, str, sizeof(str), &bw);
  // app_assert_status(ret_code);
  // app_log("Write a message to SD card success! Byte writen = %d\n\r", bw);

  // // Close file
  // ret_code = f_close(&fil);
  // app_assert_status(ret_code);

  // Open file to read
  ret_code = f_open(&fil, "hello.txt", FA_OPEN_EXISTING | FA_READ);
  app_assert_status(ret_code);

  // Read back the content and print on the console
  ret_code = f_read(&fil, f_work, sizeof(f_work), &br);
  app_assert_status(ret_code);
  app_log("Read a message from SD card success! Byte read = %d\n\r", br);
  app_log("Content: %s", f_work);

  // Close file
  ret_code = f_close(&fil);
  app_assert_status(ret_code);

  // Unmount SDCARD
  (void)f_mount(NULL, "", 1);
}

void micro_sd_process_action(void) {}
