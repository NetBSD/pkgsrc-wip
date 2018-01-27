# $NetBSD$
#

DISTNAME=	xmlsig-1.0.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	http://sourceforge.net/projects/xmlsig/ # stub

MAINTAINER=	gianni-pkgsrc-wip@daprile.net
HOMEPAGE=	http://sourceforge.net/projects/xmlsig/
COMMENT=	Multi-language, multi-platform implementation of XML signatures
LICENSE=	apache-2.0

# Get it from Subversion repository:
SVN_REPOSITORIES=	xmlsig
SVN_REPO.xmlsig=	http://svn.code.sf.net/p/xmlsig/code/trunk

WRKSRC=		${WRKDIR}/${SVN_MODULE.xmlsig}

CONFIGURE_DIRS=	perl
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake perl

PERL5_PACKLIST=	auto/xmlsig/.packlist

# swig does its thing here
pre-configure:
	cd ${WRKSRC}/perl \
	&& env ${MAKE_ENV} \
               ${MAKE_PROGRAM} ${BUILD_MAKE_FLAGS} \
               -f Makefile.perl

.include "../../lang/perl5/module.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../security/xmlsec1/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
