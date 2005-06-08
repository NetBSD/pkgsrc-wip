# $NetBSD: Makefile,v 1.3 2005/06/08 15:47:02 dillo Exp $
#

DISTNAME=		wbxml2-0.9.0-patched
PKGNAME=		libwbxml2-0.9.0
CATEGORIES=		wip
MASTER_SITES=		http://multisync.sourceforge.net/files/

MAINTAINER=		ola@mrEriksson.net
HOMEPAGE=		http://libwbxml.aymerick.com/
COMMENT=		Library to handle WBXML (Patched for MultiSync)

WRKSRC=		${WRKDIR}/wbxml2-0.9.0
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
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
