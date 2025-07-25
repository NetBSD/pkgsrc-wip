# $NetBSD$

DISTNAME=	xemacs
EMACSVERSION=	21.5-b36
EMACS_DISTNAME=	xemacs-${EMACSVERSION}
CATEGORIES=	editors
MASTER_SITES=	# Use hg repository

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://www.xemacs.org/
COMMENT=	XEmacs text editor (HEAD version)

LICENSE=	gnu-gpl-v3

HG_REPOSITORIES=	xemacs
HG_REPO.xemacs=		https://foss.heptapod.net/xemacs/xemacs
WRKSRC=			${WRKDIR}/xemacs

MKPIE_SUPPORTED=	no

.include "options.mk"

LIBDIR=			${PREFIX}/lib/${DISTNAME}

.include "../../mk/bsd.prefs.mk"

USE_TOOLS+=		perl makeinfo
TEXINFO_REQD=		4.12

TOOL_DEPENDS+=		gtexinfo>=4.12:../../devel/gtexinfo

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-infopath=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--with-bignum=gmp
CONFIGURE_ARGS+=	--without-msw
#CONFIGURE_ARGS+=	--without-dump-in-exec
CONFIGURE_ARGS+=	--with-postgresql=no

CFLAGS+=		-Dunix

# Newer NetBSD base tar is not good enough, see PR bin/56080
USE_TOOLS+=		gtar
INSTALL_MAKE_FLAGS+=	TAR=${TOOLS_PATH.gtar}

# Use terminfo on NetBSD-6 and newer.
# We cannot use terminfo.*.mk as XEmacs enforces a link to termcap,
# but this is fine for us.
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "FreeBSD") && exists(/usr/include/term.h)
CPPFLAGS+=	-DTERMINFO
.endif

# Having the build path in the dumped emacs is not a problem.
CHECK_WRKREF_SKIP+=	bin/xemacs*

# The portable dumper creates a dump file with a build ID in its name
#PRINT_PLIST_AWK+=	{ gsub(/-[a-z0-9]+\.dmp$$/, "-$${XEMACS_DUMPID}.dmp"); }
PRINT_PLIST_AWK+=	{ gsub(/DOC-[a-z0-9]+$$/, "DOC-$${XEMACS_DUMPID}"); }
PLIST_SUBST+=		XEMACS_DUMPID=${XEMACS_DUMPID:!${WRKSRC}/src/xemacs -sd!}

PRINT_PLIST_AWK+=	{ gsub(/${EMACS_DISTNAME}/, "$${DISTNAME}"); }
PRINT_PLIST_AWK+=	{ gsub(/${MACHINE_GNU_PLATFORM}/, "$${MACHINE_GNU_PLATFORM}"); }

PRINT_PLIST_AWK+=	{ gsub(/^share\/applications\/xemacs\.desktop$$/, "$${PLIST.x11}&"); }

PLIST_SUBST+=		DISTNAME=${EMACS_DISTNAME}
FILES_SUBST+=		DISTNAME=${EMACS_DISTNAME}
MESSAGE_SUBST+=		DISTNAME=${EMACS_DISTNAME}

INFO_FILES=		yes

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
