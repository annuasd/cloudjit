package com.anuc.cloudJIT;

import com.anuc.cloudJIT.dao.FuncInfoDao;
import com.anuc.cloudJIT.dao.ModuleInfoDao;
import com.anuc.cloudJIT.entity.FuncInfo;
import com.anuc.cloudJIT.entity.ModuleInfo;
import com.anuc.cloudJIT.service.FuncInfoService;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.List;

@SpringBootTest
class DemoApplicationTests {

	@Autowired
	private ModuleInfoDao moduleInfoDao;
	@Autowired
	private FuncInfoService service;
	@Test
	void testGetAll() {
		List<ModuleInfo> moduleInfoList = moduleInfoDao.selectList(null);
		System.out.println(moduleInfoList);
	}
	@Test
	void tetGetByBapge() {
		IPage page = new Page(1, 1);
		moduleInfoDao.selectPage(page, null);
		System.out.println(page.getRecords());
	}
	@Test
	void funcInsert() {
		FuncInfo info = new FuncInfo();
		info.setFuncName("草死你的吗");
		info.setModuleName("test");
		service.insertFuncInfo(info);
	}

}
