# $NetBSD: Makefile,v 1.5 2024/01/28 13:29:46 wiz Exp $

# XXX: At least tree-sitter-vimdoc-2.5.1 is the latest working version with
# XXX: editors/neovim 0.10.0. Before updating please double-check via `:help` in
# XXX: neovim that the possible new version works.

DISTNAME=	tree-sitter-vimdoc-2.5.1
CATEGORIES=	textproc devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=neovim/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neovim/tree-sitter-vimdoc
COMMENT=	vimdoc grammar for tree-sitter
LICENSE=	apache-2.0

.include "../../textproc/tree-sitter/grammar.mk"
.include "../../mk/bsd.pkg.mk"
