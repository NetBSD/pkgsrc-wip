# $NetBSD: Makefile,v 1.4 2004/01/28 17:12:38 rasputnik Exp $

DISTNAME=	syck-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
WRKSRC=	${WRKDIR}/${DISTNAME}/ext/ruby
CATEGORIES=	textproc
MASTER_SITES=   http://heanet.dl.sourceforge.net/sourceforge/yaml4r/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.whytheluckystiff.net/syck/
COMMENT=		Fast YAML reader/writer for Ruby

USE_BUILDLINK2= # defined

DEPENDS+=	ruby-racc>=1.4.3:../../devel/ruby-racc
VER=	0.42
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
MAKE_FLAGS+=	SHELL=${SH}

EXAMPLES=	okayNews-modules.rb okayNews-sample.rb okayNews-validate.rb \
			okayRpc-client.rb okayRpc-server.rb yaml-sortHashKeys.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/syck
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/$f ${RUBY_EXAMPLESDIR}/syck
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
