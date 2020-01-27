# $NetBSD: Makefile,v 1.1 2013/06/12 11:36:35 noud4 Exp $
#

DISTNAME=	hunspell-dictionaries-1.0
PKGREVISION=	1
CATEGORIES=	meta-pkgs textproc
MASTER_SITES=	# blank
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.openoffice.org/wiki/Dictionaries
COMMENT=	"meta-package" for hunspell spell checker dictionaries
LICENSE=	mpl-1.1 OR gnu-lgpl-v2.1 OR gnu-gpl-v2

USE_LANGUAGES=	# none

.include "options.mk"

WRKSRC=		# blank

META_PACKAGE=	yes

.include "../../textproc/hunspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
