# $NetBSD: Makefile,v 1.4 2009/09/23 08:53:32 jihbed Exp $
#

DISTNAME=	gxmessage-2.12.3
CATEGORIES=	wip
MASTER_SITES=	http://homepages.ihug.co.nz/~trmusson/stuff/

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE
HOMEPAGE=	http://homepages.ihug.co.nz/~trmusson/stuff/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=     pkg-config msgfmt
TEXINFO_REQD=		4.0
INFO_FILES=		yes

EDGDIR=	${PREFIX}/share/examples/gxmessage

GX_FILES=	gtkrc gxaddress gxdialup gxdict  gxman gxview nautilus-word-count

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EDGDIR}
	for a in ${GX_FILES}; do  \
		${INSTALL_DATA} ${WRKSRC}/examples/$$a ${DESTDIR}${EDGDIR}/$$a;\
	done

INSTALLATIONS_DIRS=	${PKGMANDIR}/man1

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
