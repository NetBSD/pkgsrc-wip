# $NetBSD$

PKGNAME=	gtk2-engines-aurora-1.5.1
DISTFILES=	gtk2-engines-aurora_${PKGVERSION_NOREV}.orig.tar.gz	\
		gtk2-engines-aurora_${PKGVERSION_NOREV}.orig-Aurora.tar.bz2
CATEGORIES=	x11
MASTER_SITES=	http://archive.ubuntu.com/ubuntu/pool/universe/g/gtk2-engines-aurora/

MAINTAINER=	js@heap.zone
COMMENT=	Aurora Gtk+ 2 theme engine
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/aurora-1.5
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	aurora.pc.in

post-extract:
	rm ${WRKDIR}/Aurora/metacity-1/metacity-theme-2.xml~

post-install:
	${MKDIR} ${DESTDIR}${PREFIX}/share/themes
	cd ${WRKDIR} && pax -rw -pmp Aurora ${DESTDIR}${PREFIX}/share/themes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
