# $NetBSD$

PKGNAME=	gopass-1.8.6
PKGREVISION=	6
DISTNAME=	gopass-${GITHUB_TAG}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=gopasspw/}
GITHUB_PROJECT=	gopass
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.com
HOMEPAGE=	https://www.gopass.pw/
COMMENT=	The slightly more awesome Standard Unix Password Manager for Teams
LICENSE=	mit

EXTRACT_USING=	bsdtar

GO_DIST_BASE=	${GITHUB_PROJECT}-${PKGVERSION_NOREV}
GO_SRCPATH=	github.com/gopasspw/gopass/

INSTALLATION_DIRS+=	bin \
			share/bash-completion/completions \
			share/fish/vendor_completions.d \
			share/zsh/site-functions

post-build:
	cd ${WRKDIR} && \
	./bin/gopass completion bash > ${WRKSRC}/completion.bash && \
	./bin/gopass completion fish > ${WRKSRC}/completion.fish && \
	./bin/gopass completion zsh  > ${WRKSRC}/completion.zsh

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/gopass ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/completion.bash \
			${DESTDIR}${PREFIX}/share/bash-completion/completions/gopass
	${INSTALL_DATA} ${WRKSRC}/completion.fish \
			${DESTDIR}${PREFIX}/share/fish/vendor_completions.d/gopass.fish
	${INSTALL_DATA} ${WRKSRC}/completion.zsh \
			${DESTDIR}${PREFIX}/share/zsh/site-functions/_gopass

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
