# $NetBSD: Makefile,v 1.1 2005/01/05 22:50:05 mreriksson Exp $
#

DISTNAME=		wbxml2-0.9.0-patched
PKGNAME=		libwbxml2-0.9.0
CATEGORIES=		wip
MASTER_SITES=		http://multisync.sourceforge.net/files/

MAINTAINER=		ola@mrEriksson.net
HOMEPAGE=		http://libwbxml.aymerick.com/
COMMENT=		Library to handle WBXML (Patched for MultiSync)

WRKSRC=		${WRKDIR}/wbxml2-0.9.0
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

pre-configure:
	cd ${WRKSRC} && \
		${ACLOCAL} && \
		${PREFIX}/bin/libtoolize --force --copy && \
		${AUTOHEADER} && \
		${AUTOCONF} && \
		${AUTOMAKE} -acf

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
