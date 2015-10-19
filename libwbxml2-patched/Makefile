# $NetBSD: Makefile,v 1.8 2012/11/13 20:26:27 othyro Exp $
#

DISTNAME=		wbxml2-0.9.0-patched
PKGNAME=		libwbxml2-0.9.0
CATEGORIES=		textproc
MASTER_SITES=		http://multisync.sourceforge.net/files/

MAINTAINER=		ola@mrEriksson.net
HOMEPAGE=		http://libwbxml.aymerick.com:8080/
COMMENT=		Library to handle WBXML (Patched for MultiSync)

WRKSRC=			${WRKDIR}/wbxml2-0.9.0
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		aclocal autoheader autoconf automake

pre-configure:
	cd ${WRKSRC} && \
		aclocal && \
		${PREFIX}/bin/libtoolize --force --copy && \
		autoheader && \
		autoconf && \
		automake -acf

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
