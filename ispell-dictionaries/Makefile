# $NetBSD: Makefile,v 1.1.1.1 2009/11/15 02:45:26 othyro Exp $
#

DISTNAME=	ispell-dictionaries-1.0
CATEGORIES=	meta-pkgs textproc
MASTER_SITES=	# blank
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ficus-www.cs.ucla.edu/geoff/ispell.html
COMMENT=	"meta-package" for ispell spell checker dictionaries
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

DEPENDS+=	ispell-base>=3.3.02:../../textproc/ispell-base

.include "options.mk"

WRKSRC=		# blank

META_PACKAGE=	yes

.include "../../mk/bsd.pkg.mk"
