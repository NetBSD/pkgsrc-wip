# $NetBSD: Makefile,v 1.5 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=	psh-1.8.1
CATEGORIES=	shells
MASTER_SITES=	http://www.focusresearch.com/gregor/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.focusresearch.com/gregor/download/
COMMENT=	Perl Shell

PKG_SHELL=	${PREFIX}/bin/psh

DEPENDS+=	p5-BSD-Resource>=1.24:../../devel/p5-BSD-Resource
DEPENDS+=	p5-Term-ReadLine>=1.16:../../devel/p5-Term-ReadLine

PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/psh/.packlist

USE_LANGUAGES=	# none

CONF_FILES=	${EGDIR}/pshrc ${PKG_SYSCONFDIR}/pshrc
EGDIR=		${PREFIX}/share/examples/psh

REPLACE_PERL=	psh
REPLACE_PERL+=	lib/Psh/Builtins/Complete.pm
REPLACE_PERL+=	lib/Psh/Parser.pm
REPLACE_PERL+=	t/bi_tieopt.t

SUBST_CLASSES+=		postinst
SUBST_FILES.postinst=	postinstall.pl
SUBST_MESSAGE.postinst=	Substituting in post-install script
SUBST_SED.postinst=	-e 's,~/[.]psh,${DESTDIR}${PREFIX},'
SUBST_STAGE.postinst=	pre-install

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}

post-install:
	cd ${WRKSRC} && \
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR} && \
	${INSTALL_DATA} pshrc ${DESTDIR}${EGDIR} && \
	${INSTALL_DATA} examples/complete-examples ${DESTDIR}${EGDIR}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
