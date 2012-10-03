# $NetBSD: Makefile,v 1.2 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	omega-2.0.5
CATEGORIES=	physics
MASTER_SITES=	http://www.hepforge.org/archive/whizard/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://projects.hepforge.org/whizard/
COMMENT=	Optimal Monte-Carlo Event Generation Amplitudes

DEPENDS+=	ocamlweb>=1.37:../../wip/ocamlweb

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c fortran

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
