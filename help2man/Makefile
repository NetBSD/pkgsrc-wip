# $NetBSD: Makefile,v 1.1.1.1 2004/05/10 15:13:13 arved Exp $
#

DISTNAME=		help2man_1.33.1
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=help2man/}

MAINTAINER=		arved@arved.at
HOMEPAGE=       	http://www.gnu.org/software/help2man/
COMMENT=		Generate simple manual pages from program output

DEPENDS+=       	p5-gettext>=1.01:../../devel/p5-gettext

USE_BUILDLINK3=		yes
WRKSRC=			${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		help2man.info

.include "../../mk/bsd.pkg.mk"
