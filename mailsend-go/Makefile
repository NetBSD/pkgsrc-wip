# $NetBSD$

DISTNAME=	mailsend-go-1.0.10
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=muquit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/muquit/mailsend-go
COMMENT=	Multi-platform command line tool to send mail via SMTP protocol
LICENSE=	mit

EXTRACT_USING=	bsdtar

.include "go-modules.mk"

GO_BUILD_PATTERN+=	./

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/mailsend-go ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/mailsend-go.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
