# $NetBSD$

DISTNAME=	emacs-viewer-0.0
CATEGORIES=	games
GIT_REPO=	https://github.com/Gopiandcode/emacs-viewer.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Gopiandcode/emacs-viewer
COMMENT=	Web frontend for your Org-files
LICENSE=	gnu-agpl-v3

TOOL_DEPENDS+=	ocaml-dune-[0-9]*:../../devel/ocaml-dune

do-build:
	cd ${WRKSRC} && dune build --release ./bin/main.exe

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
