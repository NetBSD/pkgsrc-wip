# $NetBSD: Makefile,v 1.4 2012/10/07 17:34:22 asau Exp $
#

DISTNAME=	0.9.9-zeta
PKGNAME=	vee-0.9.9
GITHUB_TAG=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=estrabd/}

MAINTAINER=	cherry@zyx.in
HOMEPAGE=	https://estrabd.github.io/vee/
COMMENT=	Command line blog tool that is very portable across Unix systems

NO_BUILD=	yes	# no? yes!
USE_TOOLS+=	pax

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/vee ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/ && ${RM} -rf ${WRKSRC}/bin && pax -rw -pp [a,c-z,A-Z]* ${DESTDIR}${PREFIX}/share/vee

.include "../../mk/bsd.pkg.mk"
