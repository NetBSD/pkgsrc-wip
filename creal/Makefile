# $NetBSD: Makefile,v 1.1.1.1 2010/04/28 03:54:13 othyro Exp $
#

DISTNAME=	creal-0.7
CATEGORIES=	math
MASTER_SITES=	http://www.lri.fr/%7Efilliatr/ftp/ocaml/ds/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lri.fr/~filliatr/creal.en.html
COMMENT=	Exact real arithmetic library (constructive reals) for ocaml
LICENSE=	gnu-lgpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

BUILD_TARGET=	all

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
