# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:01 tvierling Exp $
#

DISTNAME=		help2man_1.33.1
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		converters
MASTER_SITES=		${MASTER_SITE_GNU:=help2man/}

MAINTAINER=		arved@arved.at
HOMEPAGE=       	http://www.gnu.org/software/help2man/
COMMENT=		Generate simple manual pages from program output

DEPENDS+=       	p5-gettext>=1.01:../../devel/p5-gettext

WRKSRC=			${WRKDIR}/${PKGNAME}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

INFO_FILES=		help2man.info

.include "../../mk/bsd.pkg.mk"
