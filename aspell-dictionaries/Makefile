# $NetBSD: Makefile,v 1.1.1.1 2009/11/15 02:23:32 othyro Exp $
#

DISTNAME=	aspell-dictionaries-1.0
CATEGORIES=	meta-pkgs textproc
MASTER_SITES=	# blank
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aspell.net/
COMMENT=	"meta-package" for aspell spell checker dictionaries
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

.include "options.mk"

WRKSRC=		# blank

META_PACKAGE=	yes

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
