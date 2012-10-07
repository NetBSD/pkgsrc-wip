# $NetBSD: Makefile,v 1.6 2012/10/07 14:53:44 asau Exp $
#

DISTNAME=	ditz-0.5
CATEGORIES=	devel

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	http://ditz.rubyforge.org/
COMMENT=	Simple, light-weight distributed issue tracker
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	none

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "19"
GIT_REPOSITORIES=	ruby19
GIT_REPO.ruby19=	git://github.com/chriskempson/Ditz-for-Ruby-1.9.2.git
GIT_MODULE.ruby19=	Ditz-for-Ruby-1.9.2
WRKSRC=				${WRKDIR}/${GIT_MODULE.ruby19}
.else
GIT_REPOSITORIES=	mainline
GIT_REPO.mainline=	git://gitorious.org/ditz/mainline.git
WRKSRC=				${WRKDIR}/${GIT_MODULE.mainline}
.endif

GEM_SPECFILE=	${WRKSRC}/ditz.gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-trollop>=1.9:../../wip/ruby-trollop
DEPENDS+=	${RUBY_PKGPREFIX}-yaml_waml>=0.3:../../wip/ruby-yaml_waml

.include "../../wip/mk/git-package.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
