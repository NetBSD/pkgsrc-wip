# $NetBSD: Makefile,v 1.1.1.1 2011/02/23 14:35:51 makoto Exp $

DISTNAME=	ghostscript-cidfonts-20000901
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	CIDFont resources for Ghostscript

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	adobe-cidfonts>=20000901:../../fonts/adobe-cidfonts

GHOSTSCRIPT_REQD=	6.53
.include	"../../wip/ghostscript/Makefile.common"

ADOBE_RESOURCEDIR=	${PREFIX}/share/Adobe/Resource
GS_RESOURCEDIR=		${PREFIX}/share/ghostscript/${GS_VERSION}/Resource

NO_CONFIGURE=		yes
NO_BUILD=		yes

FILES_SUBST+=		ADOBE_RESOURCEDIR=${ADOBE_RESOURCEDIR:Q}
FILES_SUBST+=		GS_RESOURCEDIR=${GS_RESOURCEDIR:Q}
FILES_SUBST+=		PKG_INFO=${PKG_INFO:Q}

REQD_DIRS=		${GS_RESOURCEDIR} ${GS_RESOURCEDIR}/CIDFont

do-install:	# nothing

.include "../../mk/bsd.pkg.mk"
