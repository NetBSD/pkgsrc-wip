# $NetBSD: Makefile,v 1.9 2005/08/08 12:02:51 absd Exp $
#

DISTNAME=		pgadmin3-1.2.1
CATEGORIES=		databases
MASTER_SITES=		http://www.postgresql.org/ftpsite/pgadmin3/release/v1.2.1/src/ \
			ftp://ftp.postgresql.org/pub/pgadmin3/release/v1.2.1/src/ \
			ftp://ftp.de.postgresql.org/mirror/postgresql/pgadmin3/release/v1.2.1/src/ \
			ftp://gd.tuwien.ac.at/db/www.postgresql.org/pub/pgadmin3/release/v1.2.1/src/ \
			ftp://ftp.sunsite.auc.dk/mirrors/postgresql/pgadmin3/release/v1.2.1/src/ \
			ftp://ftp6.pl.postgresql.org/pub/postgresql/pgadmin3/release/v1.2.1/src/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.pgadmin.org/
COMMENT=		GUI administration tool for PostgreSQL RDBMS

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-pgsql=${PREFIX} \
			--with-pgsql-include=${PREFIX}/include/postgresql \
			--with-wx=${PREFIX} \
			--with-wx-config=wx24-config \
			--with-pgsql=${PREFIX}
USE_TOOLS+=		gmake


PGDIR=			${PREFIX}/share/pgadmin3

# pgadmin is too dumb to create the directories in which it wants
# to install itself, so we create them for it.
pre-install:
	${INSTALL_DATA_DIR} ${PGDIR}/ui
	${INSTALL_DATA_DIR} ${PGDIR}/ui/af_ZA
	${INSTALL_DATA_DIR} ${PGDIR}/ui/ar_SA
	${INSTALL_DATA_DIR} ${PGDIR}/ui/ca_ES
	${INSTALL_DATA_DIR} ${PGDIR}/ui/common
	${INSTALL_DATA_DIR} ${PGDIR}/ui/da_DK
	${INSTALL_DATA_DIR} ${PGDIR}/ui/de_DE
	${INSTALL_DATA_DIR} ${PGDIR}/ui/el_GR
	${INSTALL_DATA_DIR} ${PGDIR}/ui/es_ES
	${INSTALL_DATA_DIR} ${PGDIR}/ui/fi_FI
	${INSTALL_DATA_DIR} ${PGDIR}/ui/fr_FR
	${INSTALL_DATA_DIR} ${PGDIR}/ui/hu_HU
	${INSTALL_DATA_DIR} ${PGDIR}/ui/id_ID
	${INSTALL_DATA_DIR} ${PGDIR}/ui/it_IT
	${INSTALL_DATA_DIR} ${PGDIR}/ui/ja_JP
	${INSTALL_DATA_DIR} ${PGDIR}/ui/lv_LV
	${INSTALL_DATA_DIR} ${PGDIR}/ui/nl_NL
	${INSTALL_DATA_DIR} ${PGDIR}/ui/pl_PL
	${INSTALL_DATA_DIR} ${PGDIR}/ui/pt_PT
	${INSTALL_DATA_DIR} ${PGDIR}/ui/ru_RU
	${INSTALL_DATA_DIR} ${PGDIR}/ui/sk_SK
	${INSTALL_DATA_DIR} ${PGDIR}/ui/sl_SI
	${INSTALL_DATA_DIR} ${PGDIR}/ui/sr_YU
	${INSTALL_DATA_DIR} ${PGDIR}/ui/tr_TR
	${INSTALL_DATA_DIR} ${PGDIR}/ui/zh_CN
	${INSTALL_DATA_DIR} ${PGDIR}/ui/zh_TW
	${INSTALL_DATA_DIR} ${PGDIR}/docs/en_US
	${INSTALL_DATA_DIR} ${PGDIR}/docs/en_US/images
	${INSTALL_DATA_DIR} ${PGDIR}/docs/en_US/pg

.include "../../mk/bsd.pkg.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../x11/wxGTK24/buildlink3.mk"

# XXX Need a wxGTK24-contrib package
 .include "../../x11/wxGTK-contrib/buildlink3.mk"
