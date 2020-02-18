# $NetBSD$

DISTNAME=	gh-0.5.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=cli/}
GITHUB_PROJECT=	cli
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cli.github.com/
COMMENT=	GitHub CLI
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME:S/gh/cli/}
GO_SRCPATH=	github.com/cli/cli

DEPENDS+=		git-base-[0-9]*:../../devel/git-base

# TODO: fill the :sha part
#GO_DEPS+=	github.com/AlecAivazis/survey/v2
#GO_DEPS+=	github.com/google/shlex
#GO_DEPS+=	github.com/hashicorp/go-version
#GO_DEPS+=	github.com/kballard/go-shellquote
#GO_DEPS+=	github.com/mattn/go-colorable
#GO_DEPS+=	github.com/mattn/go-isatty
#GO_DEPS+=	github.com/mgutz/ansi
#GO_DEPS+=	github.com/mitchellh/go-homedir
#GO_DEPS+=	github.com/spf13/cobra
#GO_DEPS+=	github.com/spf13/pflag
#GO_DEPS+=	github.com/vilmibm/go-termd
# TODO: ...and also use GODEP_REDIRECTS for these ones!
#GO_DEPS+=	golang.org/x/crypto/ssh/terminal
#GO_DEPS+=	gopkg.in/yaml.v3

CHECK_RELRO_SKIP+=	bin/gh

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/gh ${DESTDIR}${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
