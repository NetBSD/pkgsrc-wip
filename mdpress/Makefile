# $NetBSD$

GITHUB_PROJECT=	mdpress
VERSION=	0.0.15
DISTNAME=	v${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=egonSchiele/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/egonSchiele/mdpress/
COMMENT=	Make impress.js presentations from Markdown files
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${VERSION}

GEM_NAME=	${GITHUB_PROJECT}-${VERSION}
GEM_SPECFILE=	${GITHUB_PROJECT}.gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-redcarpet>=3.1.2:../../textproc/ruby-redcarpet
DEPENDS+=	${RUBY_PKGPREFIX}-trollop>=2.1.3:../../wip/ruby-trollop
DEPENDS+=	${RUBY_PKGPREFIX}-launchy>=2.4.3:../../misc/ruby-launchy
DEPENDS+=	${RUBY_PKGPREFIX}-httparty>=0.16.4:../../wip/ruby-httparty
DEPENDS+=	${RUBY_PKGPREFIX}-multi_xml>=0.6.0:../../wip/ruby-multi_xml
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=3.2.2:../../mail/ruby-mime-types

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
