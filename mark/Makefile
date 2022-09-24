# $NetBSD$

DISTNAME=	mark-8.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=kovetskiy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kovetskiy/mark
COMMENT=	Sync markdown files with Confluence pages
# XXX: commons-clause-1.0-license should be added if imported
#LICENSE=	commons-clause-1.0-license AND apache-2.0

GO_BUILD_PATTERN+=	-ldflags ' \
			-X main.version=${PKGVERSION_NOREV}'

.include "go-modules.mk"

# Avoid conflicts with mail/nmh mark(1)
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/mark ${DESTDIR}${PREFIX}/bin/mark-confluence

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
