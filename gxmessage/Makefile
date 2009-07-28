# $NetBSD: Makefile,v 1.3 2009/07/28 00:08:28 jihbed Exp $
#

DISTNAME=	gxmessage-2.12.1
CATEGORIES=	x11
MASTER_SITES=	http://homepages.ihug.co.nz/~trmusson/stuff/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://homepages.ihug.co.nz/~trmusson/programs.html#gxmessage/
COMMENT=	Gxmessage a GTK2+ based xmessage clone

PKG_DESTDIR_SUPPORT=		user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=	intltool pkg-config msgfmt
TEXINFO_REQD=		4.0
INFO_FILES=		yes

EDGDIR=	${PREFIX}/share/examples/${DISTNAME}

GX_FILES=	gtkrc gxaddress gxdialup gxdict  gxman gxview nautilus-word-count

post-install:
	${INSTALL_DATA_DIR} ${EDGDIR}
	for a in ${GX_FILES}; do  \
		${INSTALL_DATA} ${WRKSRC}/examples/$$a ${DESTDIR}${EDGDIR}/$$a;\
	done

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
