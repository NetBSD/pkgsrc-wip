# Port du theme bluecurve de Redhat
# David Ferlier - dferlier@BonBon.net

DISTNAME=	theme-gtk-bluecurve-${THEMEVERSION}
THEMEVERSION=	0.47
SUBVERSION=	3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.rutgers.edu/pub/redhat/linux/8.0/en/os/i386/SRPMS/ \
		ftp://ftp.redhat.com/redhat/linux/8.0/en/os/i386/SRPMS/	     \
		ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/linux/8.0/en/os/i386/SRPMS/ \
	        ftp://ftp.mirror.ac.uk/sites/ftp.redhat.com/pub/redhat/linux/8.0/en/os/i386/SRPMS/ \
		ftp://ftp.riken.go.jp/pub/Linux/redhat/releases/8.0/en/os/i386/SRPMS/ \
		ftp://ftp.kddlabs.co.jp/pub/Linux/packages/RedHat/redhat/linux/8.0/en/os/i386/SRPMS//


DISTFILES=	redhat-artwork-${THEMEVERSION}-${SUBVERSION}.src.rpm
MAINTAINER=	dferlier@BonBon.net

BUILD_DEPENDS+=	rpm-[0-9]*:../../misc/rpm
BUILD_DEPENDS+=	libtool:../..//devel/libtool

WRKSRC= 	${WRKDIR}/redhat-artwork-${THEMEVERSION}
USE_GNU_TOOLS+=	make
USE_X11BASE=	YES
THEMES_SUBDIRS= ${WRKSRC}/art/gtk/Bluecurve1
USE_BUILDLINK3=	YES

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@if ! (cd ${WRKDIR} && rpm2cpio ${_DISTDIR}/${DISTFILES} | cpio -i 2>/dev/null && ${GZIP_CMD} -dc redhat-artwork-${THEMEVERSION}.tar.gz | tar -xf - && ${RM} redhat-artwork-${THEMEVERSION}.tar.gz);\
		then \
			exit 1; \
		fi
	@${CP} ${FILESDIR}/Makefile-gtk1 ${WRKSRC}/art/gtk/Bluecurve1/Makefile

post-patch:
	@${CAT} ${WRKSRC}/art/gtk/Bluecurve1/Makefile |			\
		${SED} -e 's#-O2#${CFLAGS}#' >				\
		${WRKSRC}/art/gtk/Bluecurve1/Makefile

do-build:
	@for theme_dir in ${THEMES_SUBDIRS};do \
		(cd $$theme_dir; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}); \
	done

do-install:
	@${MKDIR} ${PREFIX}/share/themes/Bluecurve && ${CHMOD} a+rx ${PREFIX}/share/themes/Bluecurve
	@${MKDIR} ${PREFIX}/lib/gtk/themes/engines && ${CHMOD} a+rx ${PREFIX}/lib/gtk/themes/engines
	@${INSTALL_PROGRAM} ${WRKSRC}/art/gtk/Bluecurve1/.libs/libbluecurve.so ${PREFIX}/lib/gtk/themes/engines
	@${MKDIR} ${PREFIX}/share/themes/Bluecurve/gtk && ${CHMOD} a+rx ${PREFIX}/share/themes/Bluecurve/gtk
	@${INSTALL_DATA} ${WRKSRC}/art/gtk/Bluecurve1/gtk/gtkrc ${PREFIX}/share/themes/Bluecurve/gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
