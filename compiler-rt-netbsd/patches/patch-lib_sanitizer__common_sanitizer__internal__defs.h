$NetBSD$

--- lib/sanitizer_common/sanitizer_internal_defs.h.orig	2018-06-01 09:39:33.000000000 +0000
+++ lib/sanitizer_common/sanitizer_internal_defs.h
@@ -186,7 +186,9 @@ typedef u64 tid_t;
 // This header should NOT include any other headers to avoid portability issues.
 
 // Common defs.
+#ifndef INLINE
 #define INLINE inline
+#endif
 #define INTERFACE_ATTRIBUTE SANITIZER_INTERFACE_ATTRIBUTE
 #define SANITIZER_WEAK_DEFAULT_IMPL \
   extern "C" SANITIZER_INTERFACE_ATTRIBUTE SANITIZER_WEAK_ATTRIBUTE NOINLINE
