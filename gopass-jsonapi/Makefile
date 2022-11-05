# $NetBSD$

PKGNAME=	gopass-jsonapi-1.14.9
DISTNAME=	gopass-jsonapi-${GITHUB_TAG}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=gopasspw/}
GITHUB_PROJECT=	gopass-jsonapi
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gopasspw/gopass-jsonapi/
COMMENT=	Gopass Web Browser Bindings
LICENSE=	mit

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN=	.

INSTALLATION_DIRS+=	bin

do-build:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install -v ${GO_BUILD_PATTERN}

do-test:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_EMV} ${GO} test -test.short -run '(Test|Example)'

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/* ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
