# $NetBSD$

PKGNAME=	${GITHUB_PROJECT}-1.0.7
DISTNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=muquit/}
GITHUB_PROJECT=	mailsend-go
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://github.com/muquit/mailsend-go
COMMENT=	Multi-platform command line tool to send mail via SMTP protocol
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/muquit/mailsend-go/

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/mailsend-go ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/mailsend-go.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../wip/go-gomail/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
