# $NetBSD$

DISTNAME=	diff-pdf-0.5.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=vslavik/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vslavik/diff-pdf/
COMMENT=	Simple tool for visually comparing to PDF files
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
# doesn't need C
USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.4
.include "../../graphics/cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=0.10
.include "../../print/poppler/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
