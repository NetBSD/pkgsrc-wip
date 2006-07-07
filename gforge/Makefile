# $NetBSD: Makefile,v 1.10 2006/07/07 19:10:34 thomasklausner Exp $

DISTNAME=	gforge-3.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://gforge.org/frs/download.php/44/

MAINTAINER=	david@netbsd-fr.org
HOMEPAGE=	http://www.gforge.org/
COMMENT=	Open Source collaborative software development tool

.include "../../lang/php/phpversion.mk"

DEPENDS+=	wget>=1.9:../../net/wget
DEPENDS+=	${PHP_PKG_PREFIX}-jpgraph>=1.12:../../graphics/php-jpgraph
DEPENDS+=	${PHP_PKG_PREFIX}-pgsql>=4.3:../../databases/php-pgsql

USE_TOOLS+=	perl:run

ETCDIR=		${PKG_SYSCONFDIR}/gforge
DATADIR=	${PREFIX}/share/gforge
BACKENDDIR=	${DATADIR}/backends
DOCDIR=		${PREFIX}/share/doc/gforge

SUBST_CLASSES+=		cli
SUBST_STAGE.cli=	post-patch
SUBST_FILES.cli=	\
	common/include/timezones.php \
	common/include/account.php \
	common/include/database.php \
	common/include/ldap.php \
	common/include/session.php \
	common/include/utils.php \
	common/include/vars.php \
	contrib/beta1_install_from_scratch_install.php \
	cronjobs/mail/mailaliases.php \
	cronjobs/mail/mailing_lists_create.php \
	cronjobs/massmail.php \
	cronjobs/check_stale_tracker_items.php \
	cronjobs/calculate_user_metric.php \
	cronjobs/cvs-cron/history_parse.php \
	cronjobs/cvs-cron/cvs.php \
	cronjobs/cvs-cron/ssh_create.php \
	cronjobs/cvs-cron/usergroup.php \
	cronjobs/db_trove_maint.php \
	cronjobs/db_stats_agg.php \
	cronjobs/project_weekly_metric.php \
	cronjobs/project_cleanup.php \
	cronjobs/project_weekly_metric-backfill.php \
	cronjobs/rating_stats.php \
	cronjobs/rotate_activity.php \
	cronjobs/site_stats.php \
	cronjobs/stats_projects-backfill.php \
	cronjobs/vacuum.php \
	cronjobs/db_project_sums.php \
	db/oci8port/pssonline/database-oci8.php \
	db/oci8port/shaguo/database.php \
	db/20021213_doc_data-migrate.php \
	db/SQL_migrate-2.5-to-2.6/artifact-convert-files.php \
	docs/doc_utils.php \
	docs/index.php \
	www/account/change_email-complete.php \
	www/account/change_email.php \
	www/account/change_pw.php \
	www/account/editsshkeys.php \
	www/account/first.php \
	www/account/index.php \
	www/account/login.php \
	www/account/logout.php \
	www/account/lostlogin.php \
	www/account/lostpw.php \
	www/account/pending-resend.php \
	www/account/register.php \
	www/account/setlang.php \
	www/account/unsubscribe.php \
	www/account/verify.php \
	www/pro/index.php \
	www/tarballs.php \
	www/404.php \
	www/source.php \
	www/dbimage.php \
	www/download.php \
	www/sendmessage.php \
	www/index.php \
	www/admin/trove/trove_cat_add.php \
	www/admin/trove/trove_cat_edit.php \
	www/admin/trove/trove_cat_list.php \
	www/admin/admintabfiles.php \
	www/admin/add_language.php \
	www/admin/admin_table.php \
	www/admin/admin_utils.php \
	www/admin/edit_frs_filetype.php \
	www/admin/approve-pending.php \
	www/admin/database.php \
	www/admin/edit_supported_languages.php \
	www/admin/edit_frs_processor.php \
	www/admin/edit_frs_theme.php \
	www/admin/massmail_execute.php \
	www/admin/edittabfiles.php \
	www/admin/groupedit.php \
	www/admin/grouplist.php \
	www/admin/index.php \
	www/admin/loadtabfiles.php \
	www/admin/massmail-old.php \
	www/admin/massmail.php \
	www/admin/editnotinbasetabfiles.php \
	www/admin/responses_admin.php \
	www/admin/search.php \
	www/admin/seetabfiles.php \
	www/admin/unsubscribe.php \
	www/admin/useredit.php \
	www/admin/userlist.php \
	www/admin/vhost.php \
	www/admin/editdouble.php \
	www/admin/editnotranstabfiles.php \
	www/admin/edittranstabfiles.php \
	www/admin/gettabfiles.php \
	www/admin/seenotinbasetabfiles.php \
	www/admin/seenotranstabfiles.php \
	www/admin/seetranstabfiles.php \
	www/developer/diary.php \
	www/developer/index.php \
	www/developer/monitor.php \
	www/developer/rate.php \
	www/docman/admin/index.php \
	www/docman/include/doc_utils.php \
	www/docman/display_doc.php \
	www/docman/index.php \
	www/docman/new.php \
	www/docman/view.php \
	www/export/nitf_sfforums.php \
	www/export/index.php \
	www/export/rss_sfnews.php \
	www/export/projhtml.php \
	www/export/projnews.php \
	www/export/rss_sfnewreleases.php \
	www/export/rss_sfprojects.php \
	www/export/sf_tracker_export.php \
	www/export/trove_tree.php \
	www/export/patch_dump.php \
	www/forum/admin/index.php \
	www/forum/forum.php \
	www/forum/index.php \
	www/forum/message.php \
	www/forum/monitor.php \
	www/forum/new.php \
	www/forum/save.php \
	www/help/trove_cat.php \
	www/help/index.php \
	www/help/tracker.php \
	www/include/HTML_Graphs.php \
	www/include/bookmarks.php \
	www/include/browser.php \
	www/include/canned_responses.php \
	www/include/database-mysql.php \
	www/include/database-oci8.php \
	www/include/database-pgsql.php \
	www/include/exit.php \
	www/include/features_boxes.php \
	www/include/filechecks.php \
	www/include/graph_lib.php \
	www/include/help.php \
	www/include/html.php \
	www/include/logger.php \
	www/include/pre.php \
	www/include/proj_email.php \
	www/include/project_home.php \
	www/include/project_summary.php \
	www/include/snippet_caching.php \
	www/include/squal_exit.php \
	www/include/squal_pre.php \
	www/include/stats_function.php \
	www/include/tool_reports.php \
	www/include/trove.php \
	www/include/user_home.php \
	www/include/vote_function.php \
	www/include/menuSF.php \
	www/mail/admin/index.php \
	www/mail/mail_utils.php \
	www/mail/index.php \
	www/mail/mail_nav.php \
	www/my/bookmark_delete.php \
	www/my/bookmark_add.php \
	www/my/bookmark_edit.php \
	www/my/diary.php \
	www/my/index.php \
	www/my/rmproject.php \
	www/new/index.php \
	www/news/admin/index.php \
	www/news/admin/news_admin_utils.php \
	www/news/news_utils.php \
	www/news/index.php \
	www/news/submit.php \
	www/people/admin/index.php \
	www/people/helpwanted-latest.php \
	www/people/createjob.php \
	www/people/editjob.php \
	www/people/editprofile.php \
	www/people/people_utils.php \
	www/people/index.php \
	www/people/skills_utils.php \
	www/people/viewjob.php \
	www/people/viewprofile.php \
	www/pm/admin/index.php \
	www/pm/browse_task.php \
	www/pm/add_task.php \
	www/pm/detail_task.php \
	www/pm/calendar.php \
	www/pm/ganttpage.php \
	www/pm/gantt.php \
	www/pm/index.php \
	www/pm/mod_task.php \
	www/pm/task.php \
	www/pm/reporting/index.php \
	www/project/admin/editgroupinfo.php \
	www/project/admin/database.php \
	www/project/admin/project_admin_utils.php \
	www/project/admin/editimages.php \
	www/project/admin/editpackages.php \
	www/project/admin/editrelease.php \
	www/project/admin/group_trove.php \
	www/project/admin/history.php \
	www/project/admin/index.php \
	www/project/admin/rmuser.php \
	www/project/admin/qrs.php \
	www/project/admin/showreleases.php \
	www/project/admin/userpermedit.php \
	www/project/admin/userperms.php \
	www/project/admin/vhost.php \
	www/project/stats/stats_graph.php \
	www/project/stats/index.php \
	www/project/stats/project_stats_utils.php \
	www/project/filemodule_monitor.php \
	www/project/index.php \
	www/project/memberlist.php \
	www/project/showfiles.php \
	www/project/shownotes.php \
	www/register/projectinfo.php \
	www/register/index.php \
	www/search/index.php \
	www/snippet/add_snippet_to_package.php \
	www/snippet/addversion.php \
	www/snippet/browse.php \
	www/snippet/delete.php \
	www/snippet/detail.php \
	www/snippet/download.php \
	www/snippet/index.php \
	www/snippet/package.php \
	www/snippet/snippet_utils.php \
	www/snippet/submit.php \
	www/softwaremap/trove_list.php \
	www/softwaremap/index.php \
	www/squal/get_session_hash.php \
	www/stats/lastlogins.php \
	www/stats/graphs.php \
	www/stats/i18n.php \
	www/stats/index.php \
	www/stats/views_graph.php \
	www/stats/projects.php \
	www/stats/site_stats_utils.php \
	www/stats/users_graph.php \
	www/survey/admin/edit_question.php \
	www/survey/admin/add_question.php \
	www/survey/admin/add_survey.php \
	www/survey/admin/show_questions.php \
	www/survey/admin/edit_survey.php \
	www/survey/admin/index.php \
	www/survey/admin/show_results_csv.php \
	www/survey/admin/show_results.php \
	www/survey/admin/show_results_aggregate.php \
	www/survey/admin/show_results_comments.php \
	www/survey/admin/show_results_individual.php \
	www/survey/admin/survey_utils.php \
	www/survey/rating_resp.php \
	www/survey/index.php \
	www/survey/privacy.php \
	www/survey/survey.php \
	www/survey/survey_resp.php \
	www/survey/survey_utils.php \
	www/top/mostactive.php \
	www/top/index.php \
	www/top/toplist.php \
	www/top/topusers.php \
	www/tracker/admin/index.php \
	www/tracker/browse.php \
	www/tracker/add.php \
	www/tracker/detail.php \
	www/tracker/download.php \
	www/tracker/index.php \
	www/tracker/mod.php \
	www/tracker/reporting/index.php \
	www/tracker/mod-limited.php \
	www/tracker/taskmgr.php \
	www/scm/controller.php \
	www/scm/index.php \
	www/scm/controlleroo.php \
	www/scm/viewFile.php \
	www/redir_ad.php \
	www/themes/index.php \
	www/index_std.php \
	utils/default_page.php \
	utils/fixscripts/tools_data_cleanup.php \
	utils/fixscripts/fix_broken_uids.php \
	utils/fixscripts/fix_image_data.php \
	utils/fixscripts/upgrade_forum_data.php \
	utils/fixscripts/upgrade_bug_data.php \
	utils/fixscripts/upgrade_filerelease_data.php \
	utils/fixscripts/upgrade_task_data.php
SUBST_SED.cli=		-e "s|/usr/bin/php4|${PREFIX}/bin/php|" \
			-e "s|/usr/bin/php|${PREFIX}/bin/php|"

SUBST_CLASSES+=		patches
SUBST_STAGE.patches=	post-patch
SUBST_FILES.patches=	\
	contrib/userlist.patch \
	contrib/gforge-3.0-local_config.patch \
	contrib/gforge-3.0-cronjobs.patch \
	contrib/gforge-3.0-init_sql.patch \
	contrib/gforge-3.0-php_path.patch \
	contrib/tracker-cc.patch
SUBST_SED.patches=	-e "s|/usr/bin/php4|${PREFIX}/bin/php|" \
			-e "s|/usr/bin/php|${PREFIX}/bin/php|"

SUBST_CLASSES+=		pscripts
SUBST_STAGE.pscripts=	post-patch
SUBST_FILES.pscripts=	\
	backend/DatabaseDump.pl \
	backend/include.pl \
	db/oci8port/shaguo/pgdb-convert.pl \
	monitor/check-system.pl \
	utils/cvs1/cvstar_genlist.pl \
	utils/cvs1/cvstar_superscript.pl \
	utils/ldap/sql2ldif.pl \
	utils/ssh_create.pl \
	utils/include.pl \
	utils/new_parse.pl \
	utils/mailing_lists_create.pl \
	utils/new_aliases_parse.pl \
	utils/sort_file.pl \
	utils/underworld-dummy/dump_database.pl \
	utils/underworld-dummy/dns_conf.pl \
	utils/underworld-dummy/mail_aliases.pl \
	utils/underworld-dummy/ia64_dump.pl \
	utils/underworld-dummy/mailing_lists_dump.pl \
	utils/underworld-dummy/new_aliases.pl \
	utils/underworld-dummy/ssh_dump.pl \
	utils/missing_L10n.pl
SUBST_FILES.pscripts+=	${WRKSRC}/utils/groupCreator \
			${WRKSRC}/utils/ldap/ldap-clean \
			${WRKSRC}/utils/ldap/ldap-del-user \
			${WRKSRC}/utils/ldap/ldap-dump \
			${WRKSRC}/utils/ldap/ldap-import \
			${WRKSRC}/utils/ldap/ldap-check-replica \
			${WRKSRC}/monitor/systemdaemon
SUBST_SED.pscripts=	-e "s|/usr/bin/perl|${PERL5}|"

SUBST_CLASSES+=		wget
SUBST_STAGE.wget=	post-patch
SUBST_FILES.wget=	utils/mailing_lists_create.pl
SUBST_SED.wget=		-e "s|/usr/bin/wget|${PREFIX}/bin/wget|"

SUBST_CLASSES+=		sdaemon
SUBST_STAGE.sdaemon=	post-patch
SUBST_FILES.sdaemon=	utils/mailing_lists_create.pl
SUBST_SED.sdaemon=	-e "s|/usr/bin:/usr/games:/bin|${PATH}|"

SUBST_CLASSES+=		etcdir
SUBST_STAGE.etcdir=	post-patch
SUBST_FILES.etcdir=	backend/include.pl \
			utils/include.pl \
			www/include/BaseLanguage.class \
			www/include/pre.php \
			www/include/squal_pre.php
SUBST_SED.etcdir=	-e "s|/etc/gforge|${ETCDIR}|g"

SUBST_CLASSES+=		crontabs
SUBST_STAGE.crontabs=	post-configure
SUBST_FILES.crontabs=	cronjobs/README \
			cronjobs/README.root
SUBST_SED.crontabs=	-e "s|~/alexandria|${BACKENDDIR}|g"

do-build:

do-install:
	${FIND} ${WRKSRC} -name "*.subst.sav" -exec ${RM} {} \;
	${INSTALL_DATA_DIR} ${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/autoconf/local.inc.in \
		${ETCDIR}/local.inc-dist
	${INSTALL_DATA_DIR} ${DATADIR}
.for dir in common www
	${INSTALL_DATA_DIR} ${DATADIR}/${dir}
	${CP} -R ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor
.for dir in backend cronjobs monitor utils
	${INSTALL_DATA_DIR} ${BACKENDDIR}/${dir}
	${CP} -R ${WRKSRC}/${dir}/* ${BACKENDDIR}/${dir}
.endfor
.for dir in contrib db
	${INSTALL_DATA_DIR} ${DATADIR}/${dir}
	${CP} -R ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor
	${INSTALL_DATA_DIR} ${DOCDIR}
	${CP} -R ${WRKSRC}/docs/* ${DOCDIR}

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
