# $NetBSD: Makefile,v 1.4 2015/06/10 13:43:17 ahp-nils Exp $

DISTNAME=	asql-${VERSION}
CATEGORIES=	www databases
MASTER_SITES=	http://www.steve.org.uk/Software/asql/

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	http://www.steve.org.uk/Software/asql/
COMMENT=	Query Apache logfiles via SQL
LICENSE=	gnu-gpl-v2 OR artistic

VERSION=		1.7
USE_TOOLS+=		perl:run tar:build
NO_BUILD=		yes
DEPENDS+=		p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite
DEPENDS+=		p5-Term-ReadLine-Perl-[0-9]*:../../devel/p5-Term-ReadLine-Perl
DOCDIR=			${PREFIX}/share/doc/asql
INSTALLATION_DIRS+=	bin ${DOCDIR}
AUTO_MKDIRS=		yes
WRKSRC=			${WRKDIR}/asql-${VERSION}

REPLACE_PERL+=	bin/asql
REPLACE_PERL+=	bin/make-cmds

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/asql ${DESTDIR}${PREFIX}/bin/asql
	${INSTALL_SCRIPT} ${WRKSRC}/bin/make-cmds ${DESTDIR}${PREFIX}/bin/make-cmds
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}/README

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
