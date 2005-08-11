# $NetBSD: Makefile,v 1.4 2005/08/11 11:18:26 jgoamakf Exp $

DISTNAME=	bsfilter-1.0.9
CATEGORIES=	mail
MASTER_SITES=	http://keihanna.dl.sourceforge.jp/bsfilter/15724/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ura@jp.netbsd.org
HOMEPAGE=	http://bsfilter.org/index-e.html
COMMENT=	Bayesian spam filter written in Ruby

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=       ${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm

NO_BUILD=	yes
REPLACE_RUBY=	bsfilter/bsfilter

EXAMPLESDIR=	${PREFIX}/share/examples/bsfilter

.include "../../mk/bsd.prefs.mk"

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bsfilter/${PKGNAME:C/-[^-]*$//} ${PREFIX}/bin/${PKGNAME:C/-[^-]*$//}
	@${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for FILE in bsfilter.conf.sample dot-qmail.sample
	@${INSTALL_DATA} ${FILESDIR}/${FILE} ${EXAMPLESDIR}
.endfor
.for DIR in mda mua
	@${CP} -r ${WRKSRC}/${DIR} ${EXAMPLESDIR}/${DIR}
.endfor

.include "../../lang/ruby/replace.mk"
.include "../../mk/bsd.pkg.mk"
