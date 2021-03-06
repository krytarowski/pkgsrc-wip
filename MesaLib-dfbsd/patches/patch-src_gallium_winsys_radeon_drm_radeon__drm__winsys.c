$NetBSD: patch-src_gallium_winsys_radeon_drm_radeon__drm__winsys.c,v 1.1 2015/04/25 11:19:18 tnn Exp $

Don't create pipe thread on NetBSD. It triggers some kernel bug.
kern/49838.

--- src/gallium/winsys/radeon/drm/radeon_drm_winsys.c.orig	2017-10-19 12:23:53.000000000 +0000
+++ src/gallium/winsys/radeon/drm/radeon_drm_winsys.c
@@ -824,8 +824,10 @@ radeon_drm_winsys_create(int fd, unsigne
     /* TTM aligns the BO size to the CPU page size */
     ws->info.gart_page_size = sysconf(_SC_PAGESIZE);
 
+#if !defined(__NetBSD__)
     if (ws->num_cpus > 1 && debug_get_option_thread())
         util_queue_init(&ws->cs_queue, "radeon_cs", 8, 1, 0);
+#endif
 
     /* Create the screen at the end. The winsys must be initialized
      * completely.
