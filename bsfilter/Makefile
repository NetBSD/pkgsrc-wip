# $NetBSD: Makefile,v 1.1.1.1 2005/03/16 07:17:22 ura Exp $
# FreeBSD Id: ports/mail/bsfilter/Makefile,v 1.6 2004/08/24 19:38:56 sem Exp

DISTNAME=	bsfilter-1.0.4
CATEGORIES=	mail
MASTER_SITES=	http://keihanna.dl.sourceforge.jp/bsfilter/10876/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ura@jp.netbsd.org
HOMEPAGE=	http://bsfilter.org/index-e.html
COMMENT=	Bayesian spam filter written in Ruby

.include "../../lang/ruby/rubyversion.mk"

DEPENDS+=       ${RUBY_PKGPREFIX}-gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm

NO_BUILD=	yes
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

.include "../../mk/bsd.pkg.mk"
