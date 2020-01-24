# $NetBSD: Makefile,v 1.11 2012/12/03 12:41:17 othyro Exp $

DISTNAME=	WEPCrack-0.1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wepcrack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wepcrack.sourceforge.net/
COMMENT=	Open source tool for breaking 802.11 WEP secret keys
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_TOOLS+=	perl:run

REPLACE_PERL+=	*.pl

INSTALLATION_DIRS+=	bin

do-install:
	set -e;								\
	cd ${WRKSRC} && for f in *.pl; do				\
		${INSTALL_SCRIPT} "./$$f" ${DESTDIR}${PREFIX}/bin/;		\
	done

.include "../../mk/bsd.pkg.mk"
