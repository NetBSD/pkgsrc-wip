# $NetBSD: Makefile,v 1.3 2008/05/26 13:59:47 tnn2 Exp $
#

PKGNAME=	vee-0.9.9
DISTNAME=	vee-0.9.9-zeta
CATEGORIES=	www
MASTER_SITES=	http://vee.googlecode.com/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	cherry@zyx.in
HOMEPAGE=	http://www.0x743.com/vee/
COMMENT=	Command line blog tool that is very portable across Unix systems

NO_BUILD=	yes	# no? yes!
USE_TOOLS+=	pax

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vee ${PREFIX}/bin
	cd ${WRKSRC}/ && ${RM} -rf ${WRKSRC}/bin && pax -rw -pp [a,c-z,A-Z]* ${PREFIX}/share/vee

.include "../../mk/bsd.pkg.mk"
