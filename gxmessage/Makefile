# $NetBSD: Makefile,v 1.10 2012/09/29 00:50:42 asau Exp $
#

DISTNAME=	gxmessage-2.12.4
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://homepages.ihug.co.nz/~trmusson/stuff/

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://homepages.ihug.co.nz/~trmusson/stuff/
COMMENT=	Gxmessage a GTK2+ based xmessage clone
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=     pkg-config intltool msgfmt
TEXINFO_REQD=		4.0
INFO_FILES=		yes

EDGDIR=	${PREFIX}/share/examples/gxmessage

GX_FILES=	gtkrc gxaddress gxdialup gxdict  gxman gxview nautilus-word-count

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	for a in ${GX_FILES}; do  \
		${INSTALL_DATA} ${WRKSRC}/examples/$$a ${DESTDIR}${EDGDIR}/$$a;\
	done

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
