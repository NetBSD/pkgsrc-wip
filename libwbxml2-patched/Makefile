# $NetBSD: Makefile,v 1.7 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=		wbxml2-0.9.0-patched
PKGNAME=		libwbxml2-0.9.0
CATEGORIES=		textproc
MASTER_SITES=		http://multisync.sourceforge.net/files/

MAINTAINER=		ola@mrEriksson.net
HOMEPAGE=		http://libwbxml.aymerick.com:8080/
COMMENT=		Library to handle WBXML (Patched for MultiSync)

PKG_DESTDIR_SUPPORT=	none

WRKSRC=		${WRKDIR}/wbxml2-0.9.0
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		automake

pre-configure:
	cd ${WRKSRC} && \
		aclocal && \
		${PREFIX}/bin/libtoolize --force --copy && \
		autoheader && \
		autoconf && \
		automake -acf

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
