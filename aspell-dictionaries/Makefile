# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:39 asau Exp $
#

DISTNAME=	aspell-dictionaries-1.0
CATEGORIES=	meta-pkgs textproc
MASTER_SITES=	# blank
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	"meta-package" for aspell spell checker dictionaries
#LICENSE=	# TODO: (see mk/license.mk)

USE_LANGUAGES=	# none

.include "options.mk"

WRKSRC=		# blank

META_PACKAGE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
