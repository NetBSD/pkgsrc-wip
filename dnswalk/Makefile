# $NetBSD: Makefile,v 1.9 2012/12/03 23:43:54 othyro Exp $
#

DISTNAME=	dnswalk-2.0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dnswalk/}
LICENSE=	artistic

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dnswalk.sourceforge.net/
COMMENT=	DNS debugger

DEPENDS+=	p5-Net-DNS>=0.42:../../net/p5-Net-DNS

USE_TOOLS+=	perl:run
REPLACE_PERL=	dnswalk makereports

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

WRKSRC=		${WRKDIR}/
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dnswalk     ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/makereports ${DESTDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/sendreports ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN}    ${WRKSRC}/dnswalk.1   ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
