# $NetBSD: Makefile,v 1.7 2004/05/02 21:07:37 blef Exp $

DISTNAME=	syck-${VER}
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
WRKSRC=	${WRKDIR}/${DISTNAME}/ext/ruby
CATEGORIES=	textproc
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=yaml4r/}

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.whytheluckystiff.net/syck/
COMMENT=		Fast YAML reader/writer for Ruby

USE_BUILDLINK3= # defined

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
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
