# $NetBSD: Makefile,v 1.3 2006/08/01 19:19:09 bartoszkuzma Exp $
#

DISTNAME=		granule-1.2.1
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=granule/}

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://granule.sourceforge.net/
COMMENT=		Program for Leitner methodology for learning new words

BUILD_DEPENDS+=		p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

USE_DIRS+=		xdg-1.1
USE_LANGUAGES+=		c++
USE_LANGUAGES+=		fortran
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/libassa/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
