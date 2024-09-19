# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:41 othyro Exp $
#

DISTNAME=	itools-1.0
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=ITL
COMMENT=	Islamic hijri date and prayer time utilities
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl

REPLACE_PERL+=	ireminder

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1


.include "../../wip/libitl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
