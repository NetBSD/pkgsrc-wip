# $NetBSD: Makefile,v 1.2 2004/12/16 22:19:44 thomasklausner Exp $

DISTNAME=	raggle-${VER}
CATEGORIES=	www textproc
MASTER_SITES=	http://www.raggle.org/files/

MAINTAINER=	rasputnik@hellooperator.net
HOMEPAGE=	http://www.raggle.org/
COMMENT=	Console-based screen(1)-aware RSS reader written in Ruby

DEPENDS+=	${RUBY_PKGPREFIX}-syck>=0.42:../../wip/ruby-syck
DEPENDS+=	${RUBY_PKGPREFIX}-ncurses>=0.8:../../wip/ruby-ncurses

.include "../../lang/ruby/rubyversion.mk"
.if ${RUBY_VER} == "16"
DEPENDS+=	${RUBY_PKGPREFIX}-rexml>=2.4.0:../../textproc/ruby-rexml
.endif

VER=  		0.2.4
#MAKE_ENV+=	RUBY_VER
NO_BUILD=	yes

REPLACE_RUBY=	raggle extras/feed_dump.rb extras/feed_sizes.rb \
		extras/rss_dir_list.rb extras/rss_grab.rb

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
