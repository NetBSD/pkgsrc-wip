# $NetBSD: Makefile,v 1.2 2012/10/07 17:17:50 asau Exp $
#

DISTNAME=	ttytter-1.2.02
CATEGORIES=	net
MASTER_SITES=	-http://www.floodgap.com/software/ttytter/dist1/1.2.02.txt
EXTRACT_SUFX=

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.floodgap.com/software/ttytter/dist1/
COMMENT=	Twitter client written in perl
#LICENSE=	# The Floodgap Free Software License

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none
NO_BUILD=	yes

DEPENDS+=	curl-[0-9]*:../../www/curl
DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=	p5-Term-ReadLine-Perl-[0-9]*:../../devel/p5-Term-ReadLine-Perl

REPLACE_PERL=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/${PKGNAME_NOREV} bin

SUBST_CLASSES+=		tt
SUBST_STAGE.tt=		pre-install
SUBST_MESSAGE.tt=	Set path
SUBST_FILES.tt=		ttytter.sh
SUBST_SED.tt=		-e 's,@TT_PATH@,${PREFIX}/share/${PKGNAME_NOREV},g'

pre-configure:
	 ${INSTALL_DATA} ${FILESDIR}/ttytter.sh ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PKGNAME_NOREV} \
		${DESTDIR}${PREFIX}/share/${PKGNAME_NOREV}/ttytter
	${INSTALL_SCRIPT} ${WRKSRC}/ttytter.sh \
		${DESTDIR}${PREFIX}/bin/ttytter

.include "../../mk/bsd.pkg.mk"
