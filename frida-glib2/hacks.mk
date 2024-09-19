# $NetBSD: hacks.mk,v 1.10 2013/04/20 09:17:32 obache Exp $

.if !defined(GLIB2_HACKS_MK)
GLIB2_HACKS_MK=	# defined

# Build without optimization. Avoids crash in libgobject on gtk2
# initialization. Bug is triggered regardless of whether we're using gcc or
# aCC.
.if !empty(MACHINE_PLATFORM:MHPUX-*-hppa)
PKG_HACKS+=	hppa-codegen
CFLAGS:=	-O0 ${CFLAGS:C/[+,-]O[0-9]?//g}
.endif

.if ${OPSYS} == "Darwin"
CHECK_BUILTIN.libiconv:=	yes
.  include "../../converters/libiconv/builtin.mk"
CHECK_BUILTIN.libiconv:=	no
.  if !empty(USE_BUILTIN.iconv:M[Yy][Ee][Ss])
PKG_HACKS+=		darwin-iconv
SUBST_CLASSES+=		iconv
SUBST_STAGE.iconv=	pre-configure
SUBST_MESSAGE.iconv=	Changing libiconv_open to iconv_open.
SUBST_FILES.iconv=	configure
SUBST_SED.iconv=	-e 's,libiconv_open,iconv_open,g'
.  endif
.endif

# Work around unresolved symbol g_test_config_vars during build
.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Msunpro)
PKG_HACKS+=		sunpro-visibility
CONFIGURE_ARGS+=	--disable-visibility
.endif

#
# GLib2>=2.36 depends on builtin functions which enabled with i486 and
# later with GCC.
#
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-5]*-i386)
GNU_ARCH.i386=		i486
CFLAGS+=		-march=i486
.endif

.endif
