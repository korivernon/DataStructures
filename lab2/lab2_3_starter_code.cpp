	#include<iostream>
	#include<ctime>
	#include<iomanip>
	#include<time.h>

	using namespace std;
	void fillData(float**, int N, int M);
	void displayData(float**, int N, int M);
	float avgScore4oneStudent(float**,int studentIndex, int M);
	float avgScore4oneCourse(float **, int courseIndex, int N);
	float* avgScore4allstudents(float **scoreTable, int N, int M);
	float* avgScore4allCourses(float **scoreTable, int N, int M);
	float minScorerInCourse(float **scoreTable, int N, int M, int courseIndex, int &student);
	void minScorerInAllcourses(float **scoreTable, int N, int M, int minScorers[], float minScores[]);

	int main()
	{
		float **scoreTable;
		
		int N,M;
		cout<<"Enter number of students :";
		cin>>N;
		cout<<"Enter number of subjects :";
		cin>>M;
		//Create a Dynamic 2DArray
		//
		scoreTable = new float* [N];
		for (int i=0; i < N; i++) {
			scoreTable[i] = new float[M];
		}

		fillData(scoreTable,N,M);
		displayData(scoreTable,N,M);
		cout<<"---------------------------------"<<endl;
		cout<<"Avg. score for student[0]: "<<avgScore4oneStudent(scoreTable,0,M)<<endl;
		cout<<"---------------------------------"<<endl;
		cout<<"Avg. score for course[2]: "<<avgScore4oneCourse(scoreTable,2,N)<<endl;
		float *avgStudentScores = avgScore4allstudents(scoreTable, N, M);
		cout<<"---------------------------------"<<endl;
		for (int i=0; i<N; i++)
			cout<<"Avg. score for student["<<i<<"]= "<<avgStudentScores[i]<<endl;
		cout<<"---------------------------------"<<endl;
		float *avgCourseScore = avgScore4allCourses(scoreTable, N, M);
		cout<<"---------------------------------"<<endl;
		for (int i=0; i<M; i++)
			cout<<"Avg. score for course["<<i<<"]= "<<avgCourseScore[i]<<endl;
		cout<<"---------------------------------"<<endl;
		int student;
		int min = minScorerInCourse(scoreTable,N,M,3,student);
		cout<<"Minimum scorer in course[3] is student["<<student<<"] who scored: "<<min<<endl;
		cout<<"---------------------------------"<<endl;
		// int minScorers[M];
		// float minScores[M];
		// minScorerInAllcourses(scoreTable,N,M,minScorers,minScores);
		// for(int i=0; i<M; i++)
		// 	cout<<"Minimum scorer in course["<<i<<"] is student["<<minScorers[i]<<"] who scored: "<<minScores[i]<<endl;

		// Do Necessary clean-ups i.e. delete Dynamically allocated variables/arrays.
		return 0;
	}
	//=================================
	void fillData(float **scoreTable, int N,int M)
	{
		srand(time(NULL));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scoreTable[i][j] = rand()%100;
			}
		}
		//complete the function
	}
	//=================================
	void displayData(float **scoreTable, int N, int M)
	{
		for (int i = 0; i < N; i++) {
			cout << "student["<< i <<"]:\t";
			for (int j = 0; j < M; j++) {
				cout << scoreTable[i][j] << "\t";
			}
			cout << "\n";
		}
	}
	// //=================================
	float avgScore4oneStudent(float **score, int studentIndex, int M)
	{
	//complete the function
	// studentIndex is the row, M is the courses 
	float average = 0;
	for (int i = 0; i < M; i++) {
		average += score[studentIndex][i];
	}
	return average/M;
	}
	//==================================
	float avgScore4oneCourse(float **scoreTable, int courseIndex, int N)
	{
		float average = 0;
		for(int i = 0; i < N; i++) {
			average += scoreTable[courseIndex][i];
		}
		return average/N;
	//complete the function
	}
	//===================================
	float* avgScore4allstudents(float **scoreTable, int N, int M)
	{
		
		float *avgarray;
		avgarray = new float[25];
		for (int i = 0; i < N; i++) {
			float average = 0;
			for(int j = 0; j < M; j++ ) {
				average+=scoreTable[i][j];
			}
			avgarray[i] = (float)average/(float)N;
		}
	//complete the function
	return avgarray;
	}
	//===================================
	float* avgScore4allCourses(float **scoreTable, int N, int M)
	{
	//complete the function
	float *avgarr;
	avgarr = new float[25];
	for (int i = 0; i < M; i++) {
		float average = 0;
		for(int j = 0; j < N; j++) {
			average += scoreTable[i][j];
		}
		avgarr[i] = (float)average/(float)M;
		// taking the average of each row. 
	}
	return avgarr;
	}
	//===================================
	float minScorerInCourse(float **scoreTable, int N, int M, int courseIndex, int &student )
	{
	//complete the function
	float lowest = 101;
	for (int i; i < N; i++) {
		cout << scoreTable[courseIndex][i] << endl;
		if( lowest > scoreTable[courseIndex][i]){
			lowest = scoreTable[courseIndex][i];
		}
	}
	return lowest;
	}
	//=====================================
	void minScorerInAllcourses(float **scoreTable, int N, int M, int minScorers[], float minScores[])
	{
	//complete the function
	
	}