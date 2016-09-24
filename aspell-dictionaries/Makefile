# $NetBSD: Makefile,v 1.4 2013/04/10 00:28:36 othyro Exp $
#

DISTNAME=	aspell-dictionaries-1.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs textproc
MASTER_SITES=	# blank
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	"meta-package" for aspell spell checker dictionaries
#LICENSE=	# blank

USE_LANGUAGES=	# none

.include "options.mk"

WRKSRC=		# blank

META_PACKAGE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
