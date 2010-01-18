# $NetBSD: Makefile,v 1.12 2010/01/18 09:38:33 thomasklausner Exp $
# Port du theme bluecurve de Redhat
# David Ferlier - dferlier@BonBon.net

DISTNAME=	redhat-artwork-${THEMEVERSION}-${SUBVERSION}.src
PKGNAME=	theme-gtk-bluecurve-${THEMEVERSION}
THEMEVERSION=	0.47
SUBVERSION=	3
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.rutgers.edu/pub/redhat/linux/8.0/en/os/i386/SRPMS/ \
		ftp://ftp.redhat.com/redhat/linux/8.0/en/os/i386/SRPMS/	     \
		ftp://ftp.nluug.nl/site/ftp.redhat.com/redhat/linux/8.0/en/os/i386/SRPMS/ \
	        ftp://ftp.mirror.ac.uk/sites/ftp.redhat.com/pub/redhat/linux/8.0/en/os/i386/SRPMS/ \
		ftp://ftp.riken.go.jp/pub/Linux/redhat/releases/8.0/en/os/i386/SRPMS/ \
		ftp://ftp.kddlabs.co.jp/pub/Linux/packages/RedHat/redhat/linux/8.0/en/os/i386/SRPMS//
EXTRACT_SUFX=	.rpm

MAINTAINER=	dferlier@BonBon.net
COMMENT=	RedHat bluecurve theme for GTK

BUILD_DEPENDS+=	rpm-[0-9]*:../../misc/rpm

WRKSRC=	${WRKDIR}/redhat-artwork-${THEMEVERSION}
USE_TOOLS+=	gmake
THEMES_SUBDIRS= ${WRKSRC}/art/gtk/Bluecurve1
USE_LIBTOOL=	YES

BUILD_DIRS=	${THEMES_SUBDIRS}
MAKE_FLAGS+=	GTK_CONFIG=${BUILDLINK_PREFIX.gtk}/bin/gtk-config
MAKE_FLAGS+=	GDK_PIXBUF_CONFIG=${BUILDLINK_PREFIX.gdk-pixbuf}/bin/gdk-pixbuf-config

do-extract:
	@if ! (cd ${WRKDIR} && rpm2cpio ${_DISTDIR}/${DISTFILES} | cpio -i 2>/dev/null && ${GZIP_CMD} -dc redhat-artwork-${THEMEVERSION}.tar.gz | tar -xf - && ${RM} redhat-artwork-${THEMEVERSION}.tar.gz);\
		then \
			exit 1; \
		fi
	@${CP} ${FILESDIR}/Makefile-gtk1 ${WRKSRC}/art/gtk/Bluecurve1/Makefile

do-configure:
	@${CAT} ${WRKSRC}/art/gtk/Bluecurve1/Makefile |			\
		${SED} -e 's#-O2#${CFLAGS}#' >				\
		${WRKSRC}/art/gtk/Bluecurve1/Makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/themes/Bluecurve
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gtk/themes/engines
	${INSTALL_LIB} ${WRKSRC}/art/gtk/Bluecurve1/.libs/libbluecurve.so \
		${PREFIX}/lib/gtk/themes/engines
	${INSTALL_DATA_DIR} ${PREFIX}/share/themes/Bluecurve/gtk
	${INSTALL_DATA} ${WRKSRC}/art/gtk/Bluecurve1/gtk/gtkrc \
		${PREFIX}/share/themes/Bluecurve/gtk

.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
