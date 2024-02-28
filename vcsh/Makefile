# $NetBSD$

DISTNAME=	vcsh-2.0.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=RichiH/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	sasha-pkgsrc@arcocene.org
HOMEPAGE=	https://github.com/RichiH/vcsh/
COMMENT=	Version Control System for the home directory
LICENSE=	gnu-gpl-v2

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-Shell-Command-[0-9]*:../../wip/p5-Shell-Command
TOOL_DEPENDS+=	p5-Test-Most-[0-9]*:../../devel/p5-Test-Most
TOOL_DEPENDS+=	p5-Text-Diff-[0-9]*:../../textproc/p5-Text-Diff
TOOL_DEPENDS+=	${RUBY_PKGPREFIX}-ronn-[0-9]*:../../devel/ruby-ronn
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

USE_LANGUAGES=		c
USE_TOOLS=		autoconf automake gmake perl awk
USE_TOOLS+=		grep:run sed:run wc:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	AWK=${AWK} GREP=${GREP} SED=${SED} WC=${WC}
CONFIGURE_ARGS+=	--with-bash-completion-dir=${PREFIX:Q}/share/bash-completion/completions/${PKGBASE}
CONFIGURE_ARGS+=	--with-zsh-completion-dir=${PREFIX:Q}/share/zsh/site-functions/_${PKGBASE}

.include "../../lang/ruby/rubyversion.mk"
.include "../../mk/bsd.pkg.mk"
